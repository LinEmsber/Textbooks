int get_vec_element(vec_ptr v, long int index, data_t *dest)
{
	if (index < 0 || index >= v->len)
		return 0;
	*dest = v->data[index];
	return 1;
}

long int vec_length(vec_ptr v)
{
	return v->len;
}

data_t *get_vec_start(vec_ptr v)
{
	return v->data;
}


/* Implementation with maximum use of data abstraction */
void combine1(vec_ptr v, data_t *dest)
{
	long int i;
	*dest = IDENT;
	for (i = 0; i < vec_length(v); i++) {
		data_t val;
		get_vec_element(v, i, &val);
		*dest = *dest OP val;
	}
}


/* Move call to vec_length out of loop */
void combine2(vec_ptr v, data_t *dest)
{
	long int i;
	long int length = vec_length(v);

	*dest = IDENT;
	for (i = 0; i < length; i++) {
		data_t val;
		get_vec_element(v, i, &val);
		*dest = *dest OP val;
	}
}

/* Direct access to vector data, -O1, page. 491 */
void combine3(vec_ptr v, data_t *dest)
{
	long int i;
	long int length = vec_length(v);
	data_t *data = get_vec_start(v);
	*dest = IDENT;
	for (i = 0; i < length; i++) {
		*dest = *dest OP data[i];
	}
}

.L498:					loop:
	movss	(%rbp), %xmm0			Read product from dest
	mulss	(%rax, %rdx, 4), %xmm0		Multiply product by data[i]
	movss	^xmm0, (%rbp)			Store product at dest
	addq	$1, %rdx			Increment i
	compq	%rdx, %r12			Compare i: limit
	jg	.L498				If >, goto loop


/* Direct access to vector data, -O2, page. 495 */
void combine3_(vec_ptr v, data_t *dest)
{
	long int i;
	long int length = vec_length(v);
	data_t *data = get_vec_start(v);
	data_t *acc = IDENT;
	for (i = 0; i < length; i++) {
		acc = acc OP data[i];
		*dest = acc;
	}
}

combine3_: data_t = float, OP = *, compiled -O2 i in %rdx, data in %rax, limit in %rbp, dest at %rx12
Product in %xmm0

.L560:                      		loop:
	mulss	(%rax,%rdx,4),			%xmm0 Multiply product by data[i]
	addq	$1, %rdx			Increment i
	cmpq	%rdx, %rbp			Compare limit:i
	movss	%xmm0, (%r12)			Store product at dest
	jg	.L560				If >, goto loop


/* Accumulate result in local variable */
void combine4(vec_ptr v, data_t *dest)
{
	long int i;
	long int length = vec_length(v);
	data_t *data = get_vec_start(v);
	data_t acc = IDENT;
	for (i = 0; i < length; i++) {
		acc = acc OP data[i];
	}
	*dest = acc;
}

combine4: data_t = float, OP = * i in %rdx, data in %rax, limit in %rbp, acc in %xmm0
.L488:                              	loop:
	mulss 	(%rax,%rdx,4), %xmm0		Multiply acc by data[i]
	addq 	$1, %rdx			Increment i
	cmpq 	%rdx, %rbp			Compare limit:i
	jg 	.L488				If >, goto loop
