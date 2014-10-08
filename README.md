isf_notepad
===========

SQL Formatter plugin for Notepad++

####Install
Just download [sqlformat.dll](https://github.com/sqlparser/isf_notepad/blob/master/bin/sqlFormat.dll?raw=true)
and put it into Notepad++\plugins directory and then restart Notepad++.

This sql formatter plugin works under Notepad++ v5.1 and later.

####Usage
You can format all or any selected SQL in editor by click "Format" via Plugins->SQL Format.

You can add "Format SQL" into Context Menu by select Settings->Edit Popup ContextMenu,
modify contextMenu.xml by adding this line:

```
<Item FolderName="Plugin commands" PluginEntryName="SQL Format" PluginCommandItemName="Format" ItemNameAs="Format SQL"/>
```

####NOTE
In order to use this sql formatter plugin for Notepad++, you should be online.
This plugin send your SQL to our SQL FaaS server here:

https://github.com/sqlparser/sql-pretty-printer/wiki/SQL-FaaS#2-api

If you don't want to send your SQL via internet, you may conside to use 
[sql pretty printer desktop version](http://www.dpriver.com/?ref=github_isf_notepadd)


####Contact
http://www.dpriver.com

support@dpriver.com

https://github.com/sqlparser/isf_notepad


####Format options:
https://github.com/sqlparser/sql-pretty-printer/wiki/SQL-Coding-Standard-and-Guideline

####Links:
[sql pretty printer desktop version](http://www.dpriver.com/products/sqlpp/desktop_index.php)

[sql pretty printer addin for SQL Server Management Studio](http://www.dpriver.com/products/sqlpp/ssms_index.php)

[sql pretty printer addin for Visual Studio](http://www.dpriver.com/products/sqlpp/vs_index.php)

[C client sql formatter](https://github.com/sqlparser/isf_c_client)

[Java client sql formatter](https://github.com/sqlparser/isf_java_client)

[sql formatter plugin for eclipse](https://github.com/sqlparser/isf_eclipse)
