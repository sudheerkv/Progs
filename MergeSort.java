import java.util.*;

class MergeSort {
	public static void Sort(int[] input) {
		if(input.length >1) {
			int n = input.length/2;
			int[] left = Arrays.copyOfRange(input, 0, n);
           		int[] right = Arrays.copyOfRange(input,n,input.length);

            		Sort(left);
            		Sort(right);

            		Merge(input,left,right);			
		}
	}
	public static void Merge(int[] input, int[] left, int[] right) {
		int m =left.length;
		int n =right.length;
		int i=0,j=0,k=0;
		while(i<m && j<n) {
			if(left[i] < right[j])
				input[k++]=left[i++];
			else
				input[k++]=right[j++];
		}
		while(i<m)
			input[k++]=left[i++];
		while(j<n)
			input[k++]=right[j++];
	}
	public static void main(String args[]) {
		int[] input = new int[10];
		input[0]=5;
		input[1]=3;
		input[9]=4;
		input[2]=1;
		input[3]=2;
		input[4]=7;
		input[5]=11;
		input[6]=67;
		input[7]=40;
		input[8]=76;
		
		Sort(input);
		for(int i=0;i<10;i++)
			System.out.println(input[i]);
	}
}
