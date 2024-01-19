class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin() , answers.end());
        int cnt = 1,len = 0, sum=0, extra=0;
       
        for(int i=0; i<answers.size(); i++)
        {
            if( i==answers.size()-1 || answers[i]!=answers[i+1]){
                int modValue;
                modValue = cnt%(answers[i]+1);
               if(modValue) extra+=(answers[i]+1-modValue);
                cnt=1;
            }else{
                cnt++;
            }
        }
        
        return answers.size()+extra ;

    }
};
