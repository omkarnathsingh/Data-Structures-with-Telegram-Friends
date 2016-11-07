/* PROBLEM STATEMENT:
In this project, you will implement a system to accept new students at a university based on an admission mark 
that is computed based on the Tawjihi, High-School, and Placement Test grades.

Your program should assign new registered students to their majors based on their admission marks. 
Each input student should be assigned to one major only. 
The student may not be assigned to any major if (s)he didn’t pass achieve the required admission marks of majors 
for all faculties. Each major has a unique non-overlapping range of averages. 
For example, Medicine [97-99], Engineering [90-96], Science [85-89], and so on. 

Your program should read two input files. 
The containing the Name of students, Tawjihi, High-school, and Placement test grade.

The second file should contain the acceptance criteria by the university that is:
1.the Tawjihi grade’s rate in the admission mark
2.school grade’s rate in the admission mark
3.Placement test grade’s in the admission mark
4.A list of faculties and the range of their averages

Your application should have the options of:
1. Read the files;
2. Accept new students; 
3. Print (on the screen) all accepted students based on their faculties;
4. Print (on the screen) rejected students; 
5. Write accepted and not accepted students to files;
and 6. Quit 
 */


//import all the required packages
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;

//Node class for the basic constituents of each entry
//Tawjihi is the general secondary examination in Jordan and in Palestine
class Node	{
	String name;
	float tawjihi,highSchool,placementTest;
	Node next;	//to hold the address of next Node
	
}

//LinkedList class for all operations/functions required
public class SingleLinkedList {

	static Node head;
	static float Score[]=new float[3];
	static float facultyMark[][]=new float[5][2];
	static String facultyName[]=new String[5],accepted="",rejected="";
	
	//Constructor to initialize head
	public SingleLinkedList() {
		// TODO Auto-generated constructor stub
		head=null;
		
	}
	
	//function to get data from file1 and maintain the linked list
	static void getStudentsfromFile() throws IOException{
		boolean var=true;
			@SuppressWarnings("resource")
			BufferedReader BR=new BufferedReader(new FileReader("file1.txt"));
			String line=BR.readLine();
		
		//boolean var to maintain true till all lines are read from file1
		while(var) {
				
			String[] words = line.split("\t");
			Node newnode;
			newnode=new Node();
			newnode.name=words[0];
			newnode.tawjihi=Float.parseFloat(words[1]);
			newnode.highSchool=Float.parseFloat(words[2]);
			newnode.placementTest=Float.parseFloat(words[3]);
		
			newnode.next=null;
			
			if(head==null){
				head=newnode;
			}
			else	{
				Node temp=head;
				while(temp.next!=null){
					temp=temp.next;
				}
				temp.next=newnode;
			}	
			line=BR.readLine();
			if(line==null) var=false;
		}	
	}
	
	//function to get data from user and maintain the linked list
	static void getStudent() throws IOException	{
		Node newnode = null;
		newnode=new Node();
			BufferedReader BR=new BufferedReader(new InputStreamReader(System.in));
			System.out.println("\n Add student details: ");
			System.out.println("\n Enter name ");
			newnode.name=BR.readLine();
			System.out.println("\n Enter tawjihi marks: ");
			newnode.tawjihi=Float.parseFloat(BR.readLine());
			System.out.println("\n Enter high school marks: ");
			newnode.highSchool=Float.parseFloat(BR.readLine());
			System.out.println("\n Enter placement marks: ");
			newnode.placementTest=Float.parseFloat(BR.readLine());	
			newnode.next=null;
		
		if(head==null){
			head=newnode;
			
		}
		else	{
			Node temp=head;
			while(temp.next!=null){
				temp=temp.next;
			}
			temp.next=newnode;
		}
		
	}
	
	//get the data from file1 and file2 and initialize respective variables.
	static void readFiles() throws IOException	{
		
		getStudentsfromFile();
		
		@SuppressWarnings("resource")
		BufferedReader BR=new BufferedReader(new FileReader("file2.txt"));
		String line;
		for(int i=0;i<3;i++)	{
			line=BR.readLine();
			String[] words = line.split("\t");
			Score[i]=Integer.parseInt(words[2]);	
		}
		
		for(int i=0;i<5;i++){
			line=BR.readLine();
			String[] words = line.split("\t");
			facultyName[i]=words[0];
			facultyMark[i][0]=Float.parseFloat(words[2]);
			facultyMark[i][1]=Float.parseFloat(words[3]);
		}		
	}
	
	//Write the results to result.txt
	static void writetoFiles() throws IOException	{
		Writer W;
		W= new BufferedWriter(new OutputStreamWriter(new FileOutputStream("result.txt")));
		
		showStudents(0);
		showStudents(1);
		
		W.write(accepted);
		W.write(rejected);
		W.close();
	}
	
	//method to evaluate faculty based upon final marks
	//parameter: finalOne
	//return i: which is the index of faculty selected
	//return 0: in case of rejected 
	static int showFaculty(float finalOne){
		for(int i=0;i<5;i++)	{
				if(finalOne>facultyMark[i][0] && finalOne<facultyMark[i][1])	{
					return i;
				}	
		}
		return 0;
	}
	
	//method to display students 
	//parameter: int type
	//type=0 will show accepted students
	//type=1 will show rejected students
	static void showStudents(int type)	{
		if(head==null)	{
			System.out.println("\n Nothing to display");
			
		}
		else	{
			Node temp=head;
			float finalMarks;
			
			if(type==0)	{
				System.out.println("Accepted Students ");
				accepted=accepted.concat("Accepted Students ");
				
				while(temp!=null)	{
					finalMarks=temp.tawjihi*Score[0]+temp.highSchool*Score[1]+temp.placementTest*Score[2];
					finalMarks=(float) (finalMarks/100.0);
					int i=showFaculty(finalMarks);
					
					if(i>0) {
						System.out.println("Name: "+temp.name);
						System.out.println("Selected Faculty : "+facultyName[i]);
						
						accepted=accepted.concat("\nName: "+temp.name);
						accepted=accepted.concat("\nSelected Faculty : "+facultyName[i]);
					}
				temp=temp.next;
				
				}	//end of while{}				
			}	//end of type 0
			
			
			if(type==1){
				System.out.println("Rejected Students ");
				rejected=rejected.concat("\n\nRejected Students ");
				
				while(temp!=null)	{					
					finalMarks=temp.tawjihi*Score[0]+temp.highSchool*Score[1]+temp.placementTest*Score[2];
					finalMarks=(float) (finalMarks/100.0);
					int i=showFaculty(finalMarks);
					
					if(i==0) {
						System.out.println("Name: "+temp.name);
						rejected=rejected.concat("\nName: "+temp.name);
					}
					temp=temp.next;

				}	//end of while{}				
			}	//end of type=1			
		}	//end of else{}
	}   //end of method
	
	
	//main() method 
	//execution begins from here
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		while(true){
			System.out.println("\n Menu"
					+ "\n 1. Read the files "
					+ "\n 2. Accept new students"
					+ "\n 3. Print all accepted students based on their faculties"
					+ "\n 4. Print rejected students"
					+ "\n 5. Write accepted and not accepted students to files"
					+ "\n 6. Quit ");
			BufferedReader BR=new BufferedReader(new InputStreamReader(System.in));
			int choice=Integer.parseInt(BR.readLine());
	
			switch(choice){
				case 1:	readFiles();     break;
				case 2: getStudent();    break;
				case 3: showStudents(0); break;
				case 4: showStudents(1); break;
				case 5: writetoFiles();  break;
				case 6: return;
				default: System.out.println("\n Invalid Choice entered!!!"); break;
			}
		}	//end of while{}
	}	//end of main()

}		//end of class

/* Author: Omkar Nath Singh
 * for omkarnathsingh.wordpress.com
 * 
 * Important: 
 * Do not edit file1.txt and file2.txt
 * If you want to put your entries, use tabs between the characters/words in the shown
 * format only.
 */