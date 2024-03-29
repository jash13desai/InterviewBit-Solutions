// Problem Name: Convert the amount in number to words
// Problem Link: https://www.interviewbit.com/problems/convert-the-amount-in-number-to-words/

string one[] = {"", "one-", "two-", "three-", "four-", "five-", "six-", "seven-", "eight-", "nine-", "ten-", "eleven-", "twelve-", "thirteen-", "fourteen-", "fifteen-", "sixteen-", "seventeen-", "eighteen-", "nineteen-"};
string ten[] = {"", "", "twenty-", "thirty-", "forty-", "fifty-", "sixty-", "seventy-", "eighty-", "ninety-"};
string numToWords(int n, string s){
    string str = "";
    if (n > 19) str += ten[n / 10] + one[n % 10];
    else str += one[n];
    if(n) str += s;
    return str;
}
string convertToWords(long n){
    string out;
    out += numToWords((n / 10000000), "crore-");
    out += numToWords(((n / 100000) % 100), "lakh-");
    out += numToWords(((n / 1000) % 100), "thousand-");
    out += numToWords(((n / 100) % 10), "hundred-");
    if(n > 100 and n % 100) out += "and-";
    out += numToWords((n % 100), "");
    if (out == "") out = "zero";
    return out;
}
int Solution::solve(string a, string b){
    string s = convertToWords(stoi(a));
    while(s.back() == '-' or s.back() == ' ') s.erase(s.end()-1);
    if(s == b) return 1;
    return 0;
}
