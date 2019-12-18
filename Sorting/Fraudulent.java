import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] data = br.readLine().split(" ");
        int n = Integer.parseInt(data[0]);
        int d = Integer.parseInt(data[1]);
        List<Integer> arr = new ArrayList();
        Arrays.asList(br.readLine().split(" ")).forEach(val -> arr.add(Integer.parseInt(val)));
        int[] hash = new int[201];
        int sum,i,ans=0,j,k;
        for(i = 0; i<=200; i++){
            hash[i] = 0;
        }
        sum = 0;
        for(i=0;i<d;i++){
            hash[arr.get(i)]++;
        }
        for(i=0;i<=200;i++){
            sum = sum+hash[i];
            if(d%2==1 && sum>d/2){
                if(arr.get(d)>=2*i){
                    ans++;
                    break;
                }
            }
            else if(d%2==0){
                if(sum==d/2){
                    j=i+1;
                    while(j<=200 && hash[j]==0)
                        j++;
                    if(arr.get(d)>=i+j){
                        ans++;
                        break;
                    }
                }
                else if(sum>d/2){
                    if(arr.get(d)>=2*i){
                        ans++;
                        break;
                    }
                }
            }
        }
        for(i=d+1;i<n;i++){
            hash[arr.get(i-d-1)]--;
            hash[arr.get(i-1)]++;
            sum = 0;
            for(j=0;j<=200;j++){
                sum = sum+hash[j];
                if(d%2==1 && sum>d/2){
                    if(arr.get(i)>=2*j){
                        ans++;
                        break;
                    }
                }
                else if(d%2==0){
                    if(sum==d/2){
                        k=j+1;
                        while(k<=200 && hash[k]==0)
                            k++;
                        if(arr.get(i)>=j+k){
                            ans++;
                            break;
                        }
                    }
                    else if(sum>d/2){
                        if(arr.get(i)>=2*j){
                            ans++;
                            break;
                        }
                    }
                }    
            }     
        }
        System.out.println(ans);
    }
}