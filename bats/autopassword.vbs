set ws=wscript.createobject("wscript.shell")
'WScript.Echo("====Auto Password====")
'WScript.Echo("Using " & LCase(right(Wscript.fullName,11)))
'WScript.Echo("File:     " & Wscript.Arguments(0))
'WScript.Echo("Password: " & Wscript.Arguments(1))
file = chr(34) & Wscript.Arguments(0)& Chr(34)
ws.run file   '打开PDF
'wscript.sleep 500
'ws.AppActivate "口令"
wscript.sleep 1000        '设置打开后的等待时间，根据个人机器情况设置长短
ws.SendKeys Wscript.Arguments(1)   '模拟输入密码
ws.SendKeys "{ENTER}"    '回车打开pdf