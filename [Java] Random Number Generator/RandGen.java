import javax.swing.*;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;
import java.util.Vector;

public class GenGUI extends JFrame {
    static int MAX_WID = 600;
    static int MAX_HEI = 450;
    int res;
    int store_size = 0;
    Vector<String> ins = new Vector<>();
    JList<String> store_print = new JList<String>();
    boolean activator = false;

    GenGUI() {

        setSize(MAX_WID, MAX_HEI);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("EadRandomGenerator");
        // 전체 패널
        JPanel Panel_all = new JPanel();
        Panel_all.setLayout(null);
        Panel_all.setSize(MAX_WID,MAX_HEI);
        Panel_all.setBackground(Color.gray);

        // 숫자 출력부
        JPanel Print_section = new JPanel();
        Print_section.setLayout(null);
        Print_section.setBounds(20, 20, 250, 290);
        Print_section.setBackground(Color.lightGray);

        // 생성 넘버 패널 타이틀
        JLabel numtitle = new JLabel("Generated Number");
        numtitle.setFont(new Font("Copperplate Gothic", Font.BOLD, 20));
        numtitle.setForeground(Color.black);
        numtitle.setBounds(37, 10, 220, 20);

        // 생성 넘버 출력
        JLabel numprint = new JLabel();
        numprint.setBounds(15, 40, 220, 230);
        numprint.setBackground(Color.WHITE);
        numprint.setOpaque(true);

        Print_section.add(numtitle);
        Print_section.add(numprint);

        // 미니멈 맥시멈 타입
        JPanel User_setting = new JPanel();
        User_setting.setBounds(20, 320, 250, 60);
        User_setting.setLayout(null);

        JLabel Minpr = new JLabel("최소");
        Minpr.setFont(new Font("맑은 고딕", Font.BOLD,12));
        Minpr.setForeground(Color.black);
        JLabel Maxpr = new JLabel("최대");
        Maxpr.setFont(new Font("맑은 고딕", Font.BOLD,12));
        Maxpr.setForeground(Color.black);
        Minpr.setBounds(37, 5, 30, 10);
        Maxpr.setBounds(127, 5, 30, 10);

        JTextField MinSet = new JTextField(10);
        JTextField MaxSet = new JTextField(10);
        MinSet.setBounds(10, 20,80, 30);
        MaxSet.setBounds(100, 20, 80, 30);

        String str[] = {"정수"};
        JComboBox<String> options = new JComboBox<String>();
        for(int i = 0; i < str.length; i++)
            options.addItem(str[i]);
        options.setBounds(185, 20, 58, 30);

        User_setting.add(Minpr);
        User_setting.add(Maxpr);
        User_setting.add(MinSet);
        User_setting.add(MaxSet);
        User_setting.add(options);
        
        // 리스트 부
        JPanel Store_section = new JPanel();
        Store_section.setLayout(null);
        Store_section.setBounds(445, 20, 120, 360);
        Store_section.setBackground(Color.white);
        store_print.setBounds(10, 10, 100, 340);
        Store_section.add(store_print);

        // 버튼부
        JPanel Button_section = new JPanel();
        Button_section.setLayout(null);
        Button_section.setBounds(300, 20, 130, 360);

        JButton Make_command = new JButton("생성");
        Make_command.setFont(new Font("맑은 고딕", Font.BOLD, 23));
        Make_command.setForeground(Color.black);
        Make_command.addActionListener(new ActionListener() {
            int min, max;
            public void actionPerformed(ActionEvent e) {
                if(!MinSet.getText().equals("")) {
                    min = Integer.parseInt(MinSet.getText());
                }
                else {
                    JOptionPane.showMessageDialog(null, "please insert Minimum value.");
                    return;
                }
                if(!MaxSet.getText().equals("")) {
                    max = Integer.parseInt(MaxSet.getText());
                }
                else {
                    JOptionPane.showMessageDialog(null, "please insert Maximum value.");
                    return;
                }
                if(max <= min) {
                    JOptionPane.showMessageDialog(null, "max value must be bigger than min value.");
                    return;
                }

                Random random = new Random();
                res = random.nextInt((max - min) + 1) + min;
                numprint.setText(Integer.toString(res));
                numprint.setFont(new Font("맑은 고딕", Font.BOLD, 95));
                numprint.setHorizontalAlignment(JLabel.CENTER);
                activator = true;
            }
        });

        JButton Store_command = new JButton("저장");
        Store_command.setFont(new Font("맑은 고딕", Font.BOLD, 23));
        Store_command.setForeground(Color.black);
        Store_command.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if(activator) {
                    ins.addElement(Integer.toString(res));
                    store_print.setListData(ins);
                    store_print.setFont(new Font("맑은 고딕", Font.BOLD, 15));
                    store_print.setForeground(Color.black);
                    DefaultListCellRenderer rend = (DefaultListCellRenderer)store_print.getCellRenderer();
                    rend.setHorizontalAlignment(JLabel.CENTER);
                    store_print.setBounds(10, 10, 100, 340);
                    store_size++;
                }
                else {
                    JOptionPane.showMessageDialog(null, "Please make a random number.");
                    return;
                }
            }
        });

        JButton Delete_command = new JButton("삭제");
        Delete_command.setFont(new Font("맑은 고딕", Font.BOLD, 23));
        Delete_command.setForeground(Color.black);
        Delete_command.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if(store_size > 0) {
                    ins.remove(ins.size()-1);
                    store_print.setListData(ins);
                    store_print.setFont(new Font("맑은 고딕", Font.BOLD, 15));
                    store_print.setForeground(Color.black);
                    DefaultListCellRenderer rend = (DefaultListCellRenderer)store_print.getCellRenderer();
                    rend.setHorizontalAlignment(JLabel.CENTER);
                    store_print.setBounds(10, 10, 100, 340);
                    store_size--;
                }
                else {
                    JOptionPane.showMessageDialog(null, "Nothing in the storage!");
                    return;
                }
            }
        });

        JButton Sweep_command = new JButton("비우기");
        Sweep_command.setFont(new Font("맑은 고딕", Font.BOLD, 18));
        Sweep_command.setForeground(Color.black);
        Sweep_command.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if(store_size > 0) {
                    ins.clear();
                    store_print.setListData(ins);
                    store_print.setBounds(10, 10, 100, 340);
                    numprint.setText("");
                    store_size=0;
                }
                else {
                    JOptionPane.showMessageDialog(null, "Nothing in the storage!");
                    return;
                }
            }
        });

        Make_command.setBounds(20, 20, 90, 65);
        Store_command.setBounds(20, 105, 90, 65);
        Delete_command.setBounds(20, 190, 90, 65);
        Sweep_command.setBounds(20, 275, 90, 65);

        Button_section.add(Make_command);
        Button_section.add(Sweep_command);
        Button_section.add(Store_command);
        Button_section.add(Delete_command);

        Panel_all.add(Print_section);
        Panel_all.add(Button_section);
        Panel_all.add(Store_section);
        Panel_all.add(User_setting);

        add(Panel_all);

        setVisible(true);
    }

    public static void main(String[] args) {
        new GenGUI();
    }

}

/*
================================================================
패널
namepal = new JPanel("메시지"); 패널 (메시지) 생성
namepal.setBackground(Color.something)
namepal.setLayout(new FlowLayout() or something)
FlowLayout : 순서 배치
BorderLayout : 동서남북 배치
GridLayout : x,y 배치
CardLayout : 겹치게 배치
================================================================

================================================================
버튼
Container c = getContentPane(); // 컨텐트팬으로 컴포넌트 추가
c.setLayout(new FlowLayout());
JButton j = new JButton("메시지")
c.add(j) // 컨텐트 팬 c에 버튼 j 추가
================================================================

================================================================
메뉴
JMenuBar jb;
JMenu m1;
JMenuItem t1;
메뉴소속
jb.add(m1); // 메뉴바 jb에 메뉴 m1 추가 / jb -> m1
m1.add(t1); // 메뉴바 서브항목 메뉴 m1에 서브탭 t1 추가 / jb -> m1 -> t1
메뉴세팅
setJMenuBar(jb);
================================================================

================================================================
이미지 사용
사용할 이미지는 패키지 소스와 같은 폴더에 삽입
ImageIcon
setSize(x,y); 이미지 크기
ContentPane c가 있을 때,
c.setLayout(new FlowLayout());
setTitle("타이틀 메시지");

ImageIcon icon = new ImageIcon("13.PNG")
JLabel la = new JLabel("메시지", icon, SwingConstants.CENTER);
c.add(la);

이미지를 사용하여 버튼생성
setSize(x,y);
ImageIcon icon = new ImageIcon("something.PNG")
JButton b1 = new JButton(icon);
c.add(b1);

버튼 여러개중 하나만 선택하는 경우 : 버튼 그룹
ButtonGroup group = new ButtonGroup();
JRadioButton r1 = new JRadioButton("Male");
JRadioButton r2 = new JRadioButton("Female");
group.add(r1); group.add(r2);
c.add(r1); c.add(r2);

setVisible(true);

================================================================
텍스트필드
JTextField t1 = new JTextField(textsize);
c.add(t1);
JTextArea jt = new JTextArea(width, height); // 행과 열의 크기
================================================================
리스트
목록을 주고 하나 선택
String str[] = {"사과", "배", "귤", "천혜향", "오렌지"}
JList<String> st = new JList<String>(str);
c.add(st);
================================================================
콤보박스 (클릭 시 목록 출력)
String str[] = {"사과", "배", "귤", "천혜향", "오렌지"}
JComboBox<String> box1 = new JComboBox<String>();
    for(int i = 0; i < str.length(); i++) {
        box1.addItem(str[i]);
    }
c.add(box1);
================================================================
슬라이드
JSlider sld = new JSlider(JSlider.HORIZONTAL, 0, 200, 100)
c.add(sid);
================================================================
버튼 이벤트 처리
GuiEvent() {
    setSize(x, y);
    setTitle("program title");
    Container c = getContentPane();
    c.setLayout(new FlowLayout());
    JButton j = new JButton("버튼 메시지");
    j.addActionListener(this); // 클릭 감지기능 추가
    c.add(j);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
    setVisible(true);
}
public void actionPerformed(ActionEvent e) {
    JButton b = (JButton)e.getSource();
    if(b.getText() == "사과")
        b.setText("오렌지")
    else
        b.setText("사과")
        b.setBackgruond(Color.red)
}

================================================================
*/