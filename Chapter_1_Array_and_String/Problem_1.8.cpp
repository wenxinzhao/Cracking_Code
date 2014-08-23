bool isSubstring(string s1, string s2){
	if (s1.find(s2) != string::npos) 
		return true;
	else 
		return false;
}

bool isRotation(string s1, string s2){
	if (s1.length() != s2.length())
		return false;
	string s = s1 + s2;
	return isSubstring(s1 + s1, s2);
}
