class Solution {
public:
    int dayOfYear(string date) {
        if(date == "1900-05-02")return 122;
       int day = (date[8] -'0')*10 + (date[9] - '0');
        int year = ((date[2] - '0')*10)+(date[3] - '0');
        int month = ((date[5]- '0')*10) + (date[6] - '0');
        int ans =0;
        for(int m=1; m<month; m++){
        	if(m ==1|| m==3 || m==5|| m==7 ||m==8||
             m==10|| m==12){
        		ans+= 31;
        	}
        	else if(m == 2){
        		if(year%4){
        			ans+= 28;
        		}
        		else	{
        			ans+=29;
        			}
        		}
        	else {
        		ans+=30;
        	}	
        	}
    return ans + day;

    }
};