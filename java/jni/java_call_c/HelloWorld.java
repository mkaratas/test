public class HelloWorld {
	public native void displayHelloWorld();

	static {
		System.loadLibrary("hello");
	}

	public static void main(String[] args) {
		System.out.println("in main");
		new HelloWorld().displayHelloWorld();
	}
}
