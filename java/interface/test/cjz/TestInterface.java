package test.cjz;

interface Runner
{
	int i = 3;
	public void start();
	void run();
	void stop();
}

interface Eater extends Runner
{
	public final static int j = 4;
	void openMouth();
	void upAndDown();
	void goIn();
}

class TT implements Eater
{
	public void start()
	{
		System.out.println("--------------start()----------------");
	}
	public void run()
	{
		System.out.println("--------------run()----------------");
	}
	public void stop()
	{
		System.out.println("--------------stop()----------------");
	}
	public void openMouth()
	{
		System.out.println("--------------openMouth()----------------");
	}
	public void upAndDown()
	{
		System.out.println("--------------upAndDown()----------------");
	}
	public void goIn()
	{
		System.out.println("--------------goIn()----------------");
	}
	public void cjz()
	{
		System.out.println("--------------cjz()----------------");
	}
}

public class TestInterface
{
	public static void main(String[] args)
	{
		Runner tt = new TT();
		System.out.println(tt.i);
		System.out.println(Runner.i);
		tt.start();
		
		Eater ee = new TT();
		System.out.println(ee.i);
		System.out.println(Eater.j);
		ee.start();
	}
}
