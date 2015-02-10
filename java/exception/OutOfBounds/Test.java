public class Test {
	public static void main(String [] args) {
		int[] ints = new int[] {1, 2, 3, 4};
		System.out.println("before");
		/*
		try {
		System.out.println(ints[4]);
		} catch(IndexOutOfBoundsException e) {
			System.out.println("in exception");	
			throw e;
		} finally {
			System.out.println("end");
		}*/
		System.out.println(ints[4]);
		System.out.println("end");
	}
}
