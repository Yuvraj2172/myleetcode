class Solution {
    public double findMedianSortedArrays(int[] a, int[] b) {
        int k=0;
        int c[]=new int[a.length+b.length] ;
        for( int i =0 ;i<a.length+b.length;i++){
            if(i<a.length){
            c[i]=a[i];}
            else if (i>=a.length){
                c[i]=b[k];
                k+=1;
            }
        }

        Arrays.sort(c);

return c.length%2==0 ? ( (double)(c[c.length/2]+c[(c.length-1)/2])/2 ): (double)c[c.length/2];    
    }
}