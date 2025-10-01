class Solution {
public:

    string func(long d, long r) {
        unordered_map<long, long> pos;
        string str = "";
        int index = 0;

        while (r != 0) {
            if (pos.find(r) != pos.end()) {
                // Insert parentheses at correct position
                str.insert(pos[r], "(");
                str += ")";
                return str;
            }

            pos[r] = index++;

            r *= 10;
            str += to_string(r / d);
            r = r % d;
        }

        return str;
    }

    string fractionToDecimal(int numerator, int denominator) {
        
        int flag =0;
        if((numerator>0 && denominator<0)  || (numerator<0 && denominator>0)){
            flag=1;
        }
        long long num = numerator;
        long long den = denominator;
        num = abs(num);
        den = abs(den);

        //getting first part of num
        long long firstPart = num/den;
        string str1 = to_string(firstPart);

        long long remainderLeft = num - (den * (num/den));

        if(remainderLeft!=0){
            string str2 = func(den,remainderLeft);
            if(flag==1) return "-"+str1+'.'+str2;
            return str1+'.'+str2;
        }
        if(flag==1) return "-"+str1;
        else return str1;
        
        


    }
};