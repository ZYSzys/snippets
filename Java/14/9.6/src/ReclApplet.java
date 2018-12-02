import java.applet.Applet;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class ReclApplet extends Applet {

    public void init() {
        addMouseListener(new CircleListener());
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

        int dx = Math.abs(to.x-from.x);
        int dy = Math.abs(to.y-from.y);
        int x = Math.min(from.x, to.x);
        int y = Math.min(from.y,to.y);

        if(dx < dy) {
            g.setColor(Color.magenta);
            g.fillRect(x, y, dx, dy);
        }
        else if(dx > dy) {
            g.setColor(Color.yellow);
            g.fillRect(x, y, dx, dy);
        }
        else {
            g.setColor(Color.red);
            g.drawRect(x, y, dx, dy);
        }
    }
}


