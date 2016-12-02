import stone.GrinderBench;
import stone.Stone;

public class Ex4 {

public static void main(String[] args) {
		
	GrinderBench.benchmark(new MyGrinder(), 4, Stone.makeHugeStone());

	}
}
