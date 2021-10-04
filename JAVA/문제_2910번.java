import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.LinkedHashMap;

public class Main{
    public static void main(String []args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Map<Integer,Integer> m = new LinkedHashMap();
		int n , c;
		String input[] = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		c = Integer.parseInt(input[1]);
		int num[] = new int[n + 1];
		String input2[] = br.readLine().split(" ");
		for(int i = 0;i<input2.length;i++) {
			num[i] = Integer.parseInt(input2[i]);
			if(m.get(num[i]) == null)
				m.put(num[i], 1);
			else
				m.put(num[i], m.get(num[i]) + 1);
		}
		List<Entry<Integer,Integer>> li = new ArrayList<Entry<Integer, Integer>>(m.entrySet());
		
		Collections.sort(li , new Comparator<Entry<Integer, Integer>>(){
			
			public int compare(Entry<Integer, Integer> obj1, Entry<Integer, Integer> obj2) {
				return obj2.getValue().compareTo(obj1.getValue());
			}
		});
		
		for(Entry<Integer,Integer> entry: li) {
			for(int j = 0; j<entry.getValue();j++) {
				System.out.print(entry.getKey() + " ");
			}
		}
	}
}