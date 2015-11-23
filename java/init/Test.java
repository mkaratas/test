//:object/Test.java
/**
 * You can <em>even</em> insert a list
 * <ol>
 * <li> Item one
 * <li> Item two
 * </ol
 */
public class Test {
	static int a;
	boolean bool;

	public static void main(String [] args) {
		System.out.println("main.");
		System.getProperties().list(System.out);
		System.out.println(System.getProperty("user.name"));
		System.out.println(System.getProperty("java.library.path"));
	}
}
