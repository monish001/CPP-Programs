//It's working but incomplete yet.
import java.util.ArrayList;
public class HillClimbing{
	HillClimbing(ArrayList<Character> a){
		arrays = new ArrayList<ArrayList<Character>>();
		arrays.add(a);
		//computeSolution();
		printSolution();
		
	}
	void printSolution(){
		for(ArrayList<Character> array : arrays){
			for(int i=0; i<array.size(); i++){
				System.out.print(array.get(i).charValue());
			}
			System.out.println("");
		}
	}
	int heuristicArrayList(final ArrayList<Character> array, int index){
		if(index == 0 || array.size()==0) return 0;
		int ans=index;
		char ch = array.get(0).charValue();
		for(int i=1; i<index; i++){
			if(array.get(i).charValue() != ch+i){
				ans *= -1;
				return ans;
			}
		}
		return ans;
	}
	int heuristicPerturbation(ArrayList<ArrayList<Character>> arrays){
		int ans=0;
		for(ArrayList<Character> array : arrays){
			for(int i=0; i<array.size(); i++){
				ans += heuristicArrayList(array, i);
			}
		}
		return ans;
	}
	public static void main(String[] args){
		ArrayList<Character> arr = new ArrayList<Character>(4);
		arr.add('A');
		arr.add('D');
		arr.add('C');
		arr.add('B');
		HillClimbing h = new HillClimbing(arr);
	}
	ArrayList<ArrayList<Character>> arrays;
}