//FileName: ExecCommand.java
//runs any command which can be run on windows command prompt (cmd)
import java.io.IOException;  
       
public class ExecCommand 
{  
	public ExecCommand() //C:\Program Files\Adobe\Reader 8.0\Reader\AcroRd32.exe
	{  
        try 
		{  
			//String file = "faq.pdf";
			String command = "C:/Program Files/Adobe/Reader 8.0/Reader/AcroRd32.exe";// + " " + file;

            Process process = Runtime.getRuntime().exec(command);//executes the command
			process.waitFor();//waits for the process to terminate.
            System.out.println("Executing command: " + command+"\n"+process.exitValue());
        }
		catch (Exception e) 
		{  
			System.out.println(e.toString());  
        }  
    }  
      
    public static void main(String[] args) 
	{  
		new ExecCommand();  
    }
}  