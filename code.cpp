int sol(char* n) {
	string s(n);
	int arr[100000], res = 0, idx = 0, isn = 0, first = 0, second = 0;
	char sn[100000];
	for (int i = 0; i < (int) s.size(); i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			arr[idx++] = res;
			sn[isn++] = s[i];
			res = 0;
		} else {
			res *= 10;
			res += (s[i] - '0');
		}
	}
	arr[idx++] = res;
	for (int i = 0; i < isn; i++) {
		if (sn[i] == '*' || sn[i] == '/') {
			first = arr[i], second = arr[i + 1];
			int t = 0;
			if (sn[i] == '*')
				t = first * second;
			else
				t = first / second;
			arr[i] = INT_MIN;
			arr[i + 1] = t;
		}
	}
	res = 0;
	bool start = false;
	for (int i = 0, k = 0; k < isn && i < idx; i++) {
		if (!start) {
			if (arr[i] != INT_MIN) {
				res = arr[i];
				start = true;
			}
		} else {
			if (arr[i] != INT_MIN) {
				for (int r = k; r < isn; r++)
					if (sn[r] == '+' || sn[r] == '-') {
						k = r;
						break;
					}
				if (sn[k] == '+')
					res += arr[i];
				else
					res -= arr[i];
				k++;
			}
		}
	}
	return res;
}
