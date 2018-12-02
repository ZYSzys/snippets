//接口
interface player
{
	int flag = 1;
	void play();
	void pause();
	void stop();
}

//抽象类
abstract class playing
{
	public void display(Object oPara)
	{
		System.out.println(oPara);
	}
	abstract void winRun();
}

//继承了playing抽象类和实现类player接口
public class newPlay extends playing implements player {
	public static void main(String[] args) {
		newPlay p = new newPlay();
		p.play();
		p.pause();
		p.stop();
		p.winRun();
	}

	public void play()
	{
		display("newPlay play");
	}

	public void pause()
	{
		display("newPlay pause");
	}

	public void stop()
	{
		display("newPlay stop");
	}

	void winRun()
	{
		display("newPlay winRun");
	}
}