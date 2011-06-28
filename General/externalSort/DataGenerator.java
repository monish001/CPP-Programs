//ExternalSort.java to sort a very large list stored in a file say data.txt
/*ALGO
1. Take loadable part of data.txt into RAM and sort it using in-place sort say: quicksort.
2. Repeat step 1 for subsequent parts of data.txt.
3. Now we have, say, N parts of in.txt which are individually sorted.
4. Consider first x parts out of N. Read some data from each.(x can be N if N is not very big)
5. Merge sort these parts and the result to output buffer. Write the contents of buffer to disk when it's full.
6. Once these parts are sorted. Repeat from step 4 for next x parts out of N sorted parts. Do this untill all in N are considered.
*/

import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Date;
class DataGenerator{
	public static void main(String[] args) throws IOException{
		FileWriter timesFile = new FileWriter("dataTimes.txt");
		timesFile.write("Start Time: "+new Date()+"\n");
		
		DataGenerator dg = new DataGenerator();
		dg.datafile = new FileWriter("data.txt");
		for(int i=0; i</*2*/147483647; i++){
			if(i%1000 == 0)	System.out.println(i);
			dg.datafile.write(Integer.toString((new Random()).nextInt())+"\n");
		}
		dg.datafile.close();

		timesFile.write("End Time: "+new Date()+" "+Integer.MAX_VALUE);
		timesFile.close();
	}
	private	FileWriter datafile;
}