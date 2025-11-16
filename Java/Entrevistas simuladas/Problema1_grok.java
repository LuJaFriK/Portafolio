public class Problema1_grok {

	public static void main (String[]args){
        int[] arr = {1, 2, 3, 4, 5};
        int[] indices = indices_suman(arr, 7);
        System.out.println("Indices: " + indices[0] + ", " + indices[1]);
	}
	
	public static int[] indices_suman(int[] arr, int target){
	    int[] indices = new int[2];
		for(int i =0;i<arr.length;i++){
			for(int j = i+1;j<arr.length;j++){
				if(arr[i]+arr[j]==target){
					indices[0]=i;
					indices[1]=j;
					return indices;
				}
			}
		}
	    return null;
	}
}