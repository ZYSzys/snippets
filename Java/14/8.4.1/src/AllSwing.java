import javax.swing.*;
import java.awt.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.util.Vector;

public class AllSwing extends JFrame implements ItemListener {
    JPanel leftPanel = new JPanel();
    JPanel rightPanel = new JPanel();
    JLabel jLabel1 = new JLabel();
    JScrollPane rightJSP = new JScrollPane();
    JTextArea scratchPad = new JTextArea();

    JScrollPane leftJSP = new JScrollPane();
    Vector colors = new Vector();
    JList colorList = new JList(colors);

    JButton clearButton = new JButton();
    JButton printButton = new JButton();
    JComboBox shapeCombox = new JComboBox();
    JCheckBox filledCheckBox = new JCheckBox();
    
    JTextField downJTA = new JTextField();
    JScrollBar downScrollBar = new JScrollBar();

    JPanel draw = new MyJPanel();
    int shapeTag = 0;
    int colorTag = 0;
    int filledTag = 0;

    class MyJPanel extends JPanel {
        @Override
        public void paint(Graphics g) {
            int nPoints = 3;
            int[] xPoints = {0,80,50};
            int[] yPoints = {0,50,80};

            if(filledTag == 1) {
                switch (shapeTag) {
                    case 0: {
                        g.fillOval(0,0,100,100);
                        break;
                    }
                    case 1: {
                        g.fillRect(0,0,100,100);
                        break;
                    }
                    case 2: {
                        g.fillPolygon(xPoints,yPoints,nPoints);
                        break;
                    }
                }
            }
            else {
                switch (shapeTag) {
                    case 0: {
                        g.drawOval(0,0,100,100);
                        break;
                    }
                    case 1: {
                        g.drawRect(0,0,100,100);
                        break;
                    }
                    case 2: {
                        g.drawPolygon(xPoints,yPoints,nPoints);
                        break;
                    }
                }
            }
        }
    }

    public AllSwing() {
        try {
            Init();
        }catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        AllSwing as = new AllSwing();
    }

    private void Init() throws Exception {
        this.setSize(new Dimension(600,300));
        this.getContentPane().setLayout(null);
        this.setResizable(true);

        leftPanel.setBackground(Color.white);
        leftPanel.setBounds(new Rectangle(0,0,400,400));
        leftPanel.setLayout(null);
        this.getContentPane().add(leftPanel, null);

        rightPanel.setBackground(Color.white);
        rightPanel.setBounds(new Rectangle(400,0,200,400));
        rightPanel.setLayout(null);
        this.getContentPane().add(rightPanel, null);

        jLabel1.setText("Scratch pad");
        jLabel1.setBounds(new Rectangle(10,10,100,20));
        rightPanel.add(jLabel1,null);

        rightJSP.setBounds(new Rectangle(10,30,180,200));
        scratchPad.setEditable(true);
        scratchPad.setText("this is not scratch and sniff pad.");
        rightJSP.getViewport().add(scratchPad,null);
        rightPanel.add(rightJSP,null);

        leftJSP.setBounds(new Rectangle(10,10,90,190));
        colors.addElement("Red");
        colors.addElement("Orange");
        colors.addElement("Yellow");
        colors.addElement("Green");
        colors.addElement("Blue");
        colors.addElement("Purple");
        colors.addElement("Black");
        colors.addElement("White");
        colorList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        leftJSP.getViewport().add(colorList,null);
        leftPanel.add(leftJSP, null);

        clearButton.setBounds(new Rectangle(300,10,100,30));
        clearButton.setText("Clear");
        printButton.setBounds(new Rectangle(300,40,100,30));
        printButton.setText("Print");
        shapeCombox.setBounds(new Rectangle(300,80,100,30));
        shapeCombox.addItem("Circle");
        shapeCombox.addItem("Rectangle");
        shapeCombox.addItem("Triangle");
        shapeCombox.addItemListener(this);
        filledCheckBox.setBounds(new Rectangle(310,120,80,30));
        filledCheckBox.setText("filled");
        leftPanel.add(clearButton,null);
        leftPanel.add(printButton,null);
        leftPanel.add(shapeCombox,null);
        leftPanel.add(filledCheckBox,null);

        draw.setBounds(new Rectangle(110,10,190,190));
        draw.setLayout(null);
        leftPanel.add(draw,null);

        downScrollBar.setOrientation(JScrollBar.HORIZONTAL);
        downScrollBar.setBounds(10,210,290,20);
        downJTA.setText("1");
        downJTA.setBounds(300,210,100,20);
        leftPanel.add(downScrollBar,null);
        leftPanel.add(downJTA,null);

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("AllSwing");
        this.setLocation(200,150);
        this.setVisible(true);
        this.setResizable(true);
    }

    @Override
    public void itemStateChanged(ItemEvent e) {
        if(e.getSource() instanceof JComboBox) {
            shapeTag = ((JComboBox)e.getSource()).getSelectedIndex();
            draw.repaint();
        }

        if(e.getSource() instanceof JCheckBox) {
            filledTag = 1 - filledTag;
        }
    }
}
