string intToRoman(int num) {
string strrom[][10]={{"","I","II","III","IV","V","VI","VII","VIII","IX"},{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},{"","M","MM","MMM","","","","","",""}};
int i=0;
string str="";
while(num){
str = strrom[i][num % 10] + str;
num /= 10;
i++;
}
return str;
}