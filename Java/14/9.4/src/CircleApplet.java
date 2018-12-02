import java.applet.Applet;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;

public class CircleApplet extends Applet {
    int x, y;
    public void init() {
        addMouseListener(new CircleListener());
        setForeground(Color.blue);
        setBackground(Color.white);
    }
}

class CircleListener extends MouseAdapter {
    Point from, to;
    public void mousePressed(MouseEvent e) {
        Applet app = (Applet)e.getSource();
        from = e.getPoint();
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        //super.mouseReleased(e);
        Applet app = (Applet)e.getSource();
        Graphics g = app.getGraphics();
        to = e.getPoint();
        g.drawOval(Math.min(from.x, to.x), Math.min(from.y,to.y), Math.abs(to.x-from.x), Math.abs(to.y-from.y));
    }
}