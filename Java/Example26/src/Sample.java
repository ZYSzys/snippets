import java.awt.*;
import javax.swing.*;

public class Sample extends JFrame {
    public static void main(String[] args) {
        Sample sl = new Sample();
        sl.update();
    }

    Sample() {
        super("Sample");
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setSize(310, 160);
        show();
    }

    public void update() {
        repaint();
    }

    public void paint(Graphics g) {
        int [] x = {10,30,80,50,10};
        int [] y = {90,140,120,100,90};
        g.setColor(Color.cyan);

        for(int i = 0; i <= 300; i++)
        {
            g.drawLine(i, 0, i, 150);
        }
        for(int i = 0; i <= 150; i++)
        {
            g.drawLine(0, i, 300, i);
        }
        g.setColor(Color.black);
        g.drawRect(10, 30, 80, 50);
        g.drawRoundRect(110,30,80,50,20,10);
        g.drawPolygon(x, y, 5);
        g.drawOval(110,90,80,50);
        g.drawArc(210,30,80,50,0,90);
        g.fillArc(210,90,80,50,0,90);
    }
}
