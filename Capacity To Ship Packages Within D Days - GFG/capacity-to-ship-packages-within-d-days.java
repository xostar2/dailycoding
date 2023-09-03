//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N = Integer.parseInt(read.readLine());
            
            String S[] = read.readLine().split(" ");
            int[] arr = new int[N];
            
            int D = Integer.parseInt(read.readLine());
            
            for(int i=0; i<N; i++)
                arr[i] = Integer.parseInt(S[i]);

            Solution ob = new Solution();
            System.out.println(ob.leastWeightCapacity(arr,N,D));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    
   static int capdays(int mid,int []arr,int N){
        
        int load=0;
        int day=1;
        for(int i=0;i<N;i++){
            
            if(load+arr[i]>mid){
                load=arr[i];
                day=day+1;
            }
            else{
                load=load+arr[i];
            }
        }
        return day;
    }
    
    
    static int leastWeightCapacity(int[] arr, int N, int D) {
        // code here
         
         int low=-9999999;
         int high=0;
         
         for(int i=0;i<N;i++){
             high=high+arr[i];
             low=Math.max(low,arr[i]);
         }
         
         while(low<=high){
             
             int mid=(low+high)/2;
             
             int days=capdays(mid,arr,N);
             
             if(days<=D){
                 high=mid-1;
             }
             else{
                 low=mid+1;
             }
         }
         
         return low;
    }
};