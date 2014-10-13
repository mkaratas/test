public class Speed {
	void display(int b) {
		int a = b+20;
	}
	
	void display2() {
		display(10);
	}

	public static void main(String [] args) {
		Speed s = new Speed();
		for (int i=0; i< 5000000; i++) {
			s.display2();
		}
	}
}
