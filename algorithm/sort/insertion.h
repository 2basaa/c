//配�Eを引数とする場合�E,引数めE(ポインタ)とする
void insertion(int *data, int numlen) {
	/*
	key�͊�l
	i�͊�l�̃|�C���^
	j�͊�l�ƒl��ϊ�������ۂ̃|�C���^ 
	count�͎��s�� 
	*/
	
    int key, i, j;
    for (i = 1; i < numlen; i ++) {
        key = data[i];//��l������ 
        j = i - 1;
    	// �|�C���^�̑傫�������珬�������� 
        while (j >= 0 && data[j] > key) {
        	data[j+1] = data[j];
        	j --;
		}
		//�l��ϊ������� 
		data[j+1] = key;
    }
}
