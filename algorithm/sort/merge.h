void merge(int *data,int start,int mid,int end) {
	//num�̓}�[�W�\�[�g���s���ۂ̃C���f�b�N�X 
	int i, j, num;//j��left��right�̃C���f�b�N�X 
	int inf = 10000;//�\���ɑ傫���l
	//int merge_data[end+1];
	//n1��O�������̃\�[�g��
	//n2���㔼�����̃\�[�g�� 
	//�����ƉE���̔z����쐬
	int left[end+1], right[end+1];//�v�f��5,5 
	//�����̔z����쐬 
	
	j = 0;
	for (i = start; i <= mid; i++) {//5�� 
		left[j] = data[i];
		printf("left is %d\n", left[j]);
		j++;
	}
	left[j] = inf;
	//printf("%d", left[j]);
	//�E���̔z����쐬 
	j = 0;
	for (i= mid+1; i <= end ; i++) {//4�� 
		right[j] = data[i];
		printf("right is %d\n", right[j]);
		j++;
	}
	right[j] = inf;
	i = 0, j = 0;
	num = start;
	// ||�͘_���a 
	printf("start is %d\n", start);
	printf("end is %d\n", end);
	printf("change data is ");
		
	while(left[i] != inf || right[j] != inf) {
		if (left[i] == inf && right[j] == inf) {
			break;
		}
		if (left[i] <= right[j]) {
			data[num] = left[i];
			printf("%d ", data[num]);			
			i++;
		}
		else if (left[i] > right[j]) {
			data[num] = right[j]; 
			printf("%d ", data[num]);
			j++;
		}
		/*if (left[i] == inf && right[j] == inf) {
			break;
		}*/
		num ++;
	}
	//printf("\n");
	printf("\ndata is ");
	for(num = 0; num <= 7; num ++) {
		printf("%d ", data[num]);
	}
	printf("\n");
}

//�ċN�֐������s 
void merge_sort(int *data,int start,int end) {
	if (start < end) {
		int mid = (start + end) / 2;//4
		merge_sort(data, start, mid);
		merge_sort(data, mid+1, end);
		merge(data, start, mid, end);
	}
}
