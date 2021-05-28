// bsearch와 똑같이 동작하지만, 같은 원소가 있을 경우 가장 앞에 있는 원소의 포인터 반환

void *bsearchx(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void*, const void *));
int int_cmp(const int *a, const int *b);

int main(void)
{
	int size, target;
	int *p;

	printf("bsearch 함수를 사용하여 검색\n");
	printf("요소 개수 : ");
	scanf("%d", &size);

	if (size <= 0) return 0;

	int *arr = calloc(size, sizeof(int));

	printf("오름차순으로 입력\n");

	for (int i = 0; i < size; ++i)
	{
		printf("x[%d] : ", i);
		scanf("%d", &arr[i]);
	}

	printf("검색값 : ");
	scanf("%d", &target);

	p = bsearchx(&target, arr, size, sizeof(int), (int(*)(const void *, const void *)) int_cmp);

	if (p == NULL)
		puts("검색 실패\n");
	else
		printf("%d은(는) x[%d]에 있습니다.\n", target, (int)(p - arr));

	free(arr);

	return 0;
}

// key = target, base = arr, nmemb = size, size = sizeof, int_cmp = compare
void *bsearchx(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void*, const void *))
{
	int left = 0, right = nmemb - 1;

	void* target = NULL;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		int com = compar(key, (char*)base + mid * size);

		if (com == 1)
			left = mid + 1;
		else if (com == -1)
			right = mid - 1;
		else
		{
			target = (void*)((char*)base + mid * size);
			break;
		}
	}

	if (target != NULL)
	{
		while (compar(key, (char*)target - size) == 0)
			target = (void*)((char*)target - size);
	}

	return target;
}

int int_cmp(const int *a, const int *b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}
