void merge(int *data,int start,int mid,int end) {
	//numはマージソートを行う際のインデックス 
	int i, j, num;//jはleftとrightのインデックス 
	int inf = 10000;//十分に大きい値
	//int merge_data[end+1];
	//n1を前半部分のソートへ
	//n2を後半部分のソートへ 
	//左側と右側の配列を作成
	int left[end+1], right[end+1];//要素数5,5 
	//左側の配列を作成 
	
	j = 0;
	for (i = start; i <= mid; i++) {//5回分 
		left[j] = data[i];
		printf("left is %d\n", left[j]);
		j++;
	}
	left[j] = inf;
	//printf("%d", left[j]);
	//右側の配列を作成 
	j = 0;
	for (i= mid+1; i <= end ; i++) {//4回分 
		right[j] = data[i];
		printf("right is %d\n", right[j]);
		j++;
	}
	right[j] = inf;
	i = 0, j = 0;
	num = start;
	// ||は論理和 
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

//再起関数を実行 
void merge_sort(int *data,int start,int end) {
	if (start < end) {
		int mid = (start + end) / 2;//4
		merge_sort(data, start, mid);
		merge_sort(data, mid+1, end);
		merge(data, start, mid, end);
	}
}
