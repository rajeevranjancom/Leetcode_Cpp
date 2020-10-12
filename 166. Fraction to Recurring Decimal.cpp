class Solution {
public:
    string fractionToDecimal(int nums, int dens) {
        
        if (nums == 0 || dens == 0)
            return "0";
        else if(dens == 1)
            return to_string(nums);
       
        //converting to long type to avoid overflow error for INT_MAX or INT_MIN
        long num = abs((nums));
        long den = abs((dens));
        
        //storing sign in string
        string sign = "";
        if((nums<0&&dens>0) || (dens<0&&nums>0)) sign = "-";
        
        //Keeping track of all remainders post decimal point
        map <int,int> remlist;
        //index value post decimal
        int i=0;
        //Returning string variable
        string ans= "";
        
        //String to generate post decimal part
        string decimal= "";
        

        int rem = 0;
        //appending pre-decimal part
        ans += to_string(num/den);
        rem = num%den;
        
        //if not perfect division add decimal point
        if((rem)!=0){
            ans += ".";
            
        }
        
        num = rem*10;
        while(num!=0){
            if(remlist.count(num)<=0){
                remlist[num] = i;
            }else{
                //if recurring return final result by adding decimal part with recurring part
                return (sign+ans +decimal.substr(0,remlist[num])+"(" + decimal.substr(remlist[num],i-remlist[num]) + ")" );
            }
            
            if(num<den){
                remlist[num] = i;
                decimal += "0";
                num *= 10;
                i++;
            }else{
                remlist[num] = i;
                decimal += to_string(num/den);
                num = (num%den) * 10;
                i++;
            }
                
        }
        
        
        return sign+ans + decimal;
    }
};

*******************

class Solution {
public:
    string fractionToDecimal(long long int numerator, long long int denominator) {
        string ans="",dec="";
        if(numerator<0&&denominator>0)ans+="-",numerator=abs(numerator);
        else if(numerator>0&&denominator<0)ans+="-",denominator=abs(denominator);
        ans+=to_string(numerator/denominator);
        long long int rem=numerator%denominator,i=0;
        if(rem==0)return ans;
        unordered_map<int,int> remset;
        bool flag=false;
        while(rem!=0 && flag!=true){
            remset.insert(make_pair(rem,i));
            rem*=10;
            dec+=to_string(rem/denominator);
            rem=rem%denominator;
            if(remset.find(rem)!=remset.end()){
                dec.insert((*remset.find(rem)).second,"\(");
                dec+="\)";
                break;
            }
            i++;
        }
        return ans+"."+dec;
    }
};

***********************

#include <cstdlib>

#include <string>
#include <unordered_map>

class Solution {
public:
    std::string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) {
            // to avoid divide by zero
            return "";
        } else if (numerator == 0) {
            // to avoid output "-0"
            return "0";
        }

        // cast numerator and denominator to long long to avoid overflow
        // and then make them positive
        long long n = numerator, d = denominator;
        std::string num;
        if (n < 0) {
            n = abs(n);
            d *= -1;
        }
        if (d < 0) {
            // only one of numerator and denominator is negative
            d = abs(d);
            num.push_back('-');
        }

        // integer part
        num += std::to_string(n / d);
        n %= d;
        if (n == 0) {
            return std::move(num);
        }

        // fractional part
        num.push_back('.');
        std::unordered_map<long long, size_t> hash_table;
        while (n != 0) {
            // associate remainder with the position of its appearance
            auto res = hash_table.emplace(n, num.size());
            if (!res.second) {
                num.insert(res.first->second, "(");
                num.push_back(')');
                break;
            }
            n *= 10;
            num += std::to_string(n / d);
            n %= d;
        }
        return std::move(num);
    }
};


