#include <iostream>
#include <vector>
using namespace std;

struct Fraction {

    /**
     * @brief Gets numerator and denominator from a fraction
     * 
     * @param fraction: fraction to get its numerator and denominator
     * @return Numerator and denominator of that fraction
     */
    static vector <int> getNumeratorAndDenominator(string fraction){

        vector <int> res;
        int n = fraction.size();
        int minusCount = 0;

        if(n == 0) return res;
        if(fraction[0] == '/') return res;

        //Gets numerator substring
        string numerator = "";
        int i = 0;
        while(fraction[i] != '/'){

            if(minusCount > 1) return res;
            else if(fraction[i] == '-') minusCount++;
            else if(int(fraction[i]) < 47 || int(fraction[i]) > 57) return res;
            
            numerator += fraction[i++];
            if(i == n) return res;
        }

        if(i == n-1) return res;

        //Gets denominator substring
        string denominator = "";
        for(int j = i+1; j < n; j++){
            if(int(fraction[j]) < 48 || int(fraction[j]) > 57) return res;
            denominator += fraction[j];
        }

        res.push_back(stoi(numerator));
        res.push_back(stoi(denominator));

        return res;
    }


    /**
     * @brief Simplifies the fraction (does not accept whole numbers)
     * 
     * @param fraction: fraction to simplify
     * @return simplified fraction
    */
    static string simplifyFraction(string fraction){

        vector <int> numDem = getNumeratorAndDenominator(fraction);

        if(numDem.empty()) return "Invalid fraction";
        int numerator = numDem[0], denominator = numDem[1];
        if(numerator % denominator == 0) return to_string(numerator/denominator);
        int GCD = Integer::GCD(abs(numerator), denominator);
        
        return to_string(numerator/GCD) + "/" + to_string(denominator/GCD);
    }



    /**
     * @todo CONTINUE WORKING ON IT 
     * @brief converts decimal value to fraction
     * 
     * @param num: number
     * @return converted decimal value to fraction
    */
    static string convertDecimalToFraction(double num){

        string numString = to_string(num);
        int n = numString.size();
        int i = 0;

        while(numString[++i] != '.');
        string wholeNum = numString.substr(0,i);

        int j = i+1;
        int denominator = 1;
        string numeratorString = "";

        //Assigns numerator (string) and updates denominator
        while(j < n){
            numeratorString += numString[j++];
            denominator *= 10;
        } 

        string simplifiedFraction = simplifyFraction(numeratorString + "/" + to_string(denominator));

        if(wholeNum == "0") return simplifiedFraction;
        if(simplifiedFraction == "0") return wholeNum;

        return wholeNum + " " + simplifiedFraction;
    }

    
};
