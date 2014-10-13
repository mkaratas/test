public class HelloWorld {
	public native void displayHelloWorld();

	static {
		System.loadLibrary("HelloWorld");
	}

	public static void displayCallBack() {
		System.out.println("java call back");
	}

	public static void main(String [] args) {
		System.out.println("in main");
		HelloWorld p = new HelloWorld();
		p.displayHelloWorld();
	}
}
