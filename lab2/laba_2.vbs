Dim s,f,FSO,Drives,oFSO,cur,oTStream,d,file
Const Hidden = 2, System = 4
do
WScript.StdOut.WriteLine "Menu"
WScript.StdOut.WriteLine "----------------------------"
WScript.StdOut.WriteLine "1. Info about author"
WScript.StdOut.WriteLine "2. Archiving a file"
WScript.StdOut.WriteLine "3. Saving a list of disks with a free space value in notepad ."
WScript.StdOut.WriteLine "4. Exit"
WScript.StdOut.Write "Choose a task:"
s = WScript.StdIn.ReadLine
if (s="1") Then
WScript.StdOut.WriteLine "Drozdov Dmitry, ITP-11"
elseif (s="2") Then
WScript.StdOut.Write "Ykazite put':"
f = WScript.StdIn.ReadLine
WshShell.Run("C:\lab2\z.bat "+ f + " " + f + ".rar")
elseif (s="3") Then
set FSO = WScript.CreateObject("Scripting.FileSystemObject")
set Drives = FSO.Drives
set oFSO = CreateObject("Scripting.FileSystemObject")
cur = oFSO.GetParentFolderName(WScript.ScriptFullName)
set oTStream = oFSO.CreateTextFile(cur & "\file.txt", true)
for each d in Drives
        oTStream.WriteLine d & d.FreeSpace/1024
next
oTStream.Close
End if
loop until (s="4")