//驟搾ｿｽE繧貞ｼ墓焚縺ｨ縺吶ｋ蝣ｴ蜷茨ｿｽE,蠑墓焚繧・(繝昴う繝ｳ繧ｿ)縺ｨ縺吶ｋ
void insertion(int *data, int numlen) {
	/*
	keyは基準値
	iは基準値のポインタ
	jは基準値と値を変換させる際のポインタ 
	countは試行回数 
	*/
	
    int key, i, j;
    for (i = 1; i < numlen; i ++) {
        key = data[i];//基準値を決定 
        j = i - 1;
    	// ポインタの大きい順から小さい順へ 
        while (j >= 0 && data[j] > key) {
        	data[j+1] = data[j];
        	j --;
		}
		//値を変換させる 
		data[j+1] = key;
    }
}
