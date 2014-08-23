bool isUniqueChars(string a){
	int cheaker = 0;
	for (int i = 0; i < a.length(); i++){
		int val = a[i] - 'a';
		if ((cheaker & (1 << val)) > 0){
			return false;
		}			
		cheaker |= (1 << val);
	}
	return true;
}
