isf_notepad
===========

SQL Formatter plugin for Notepad++

####Install
Just download [sqlformat.dll](https://github.com/sqlparser/isf_notepad/blob/master/bin/sqlFormat.dll?raw=true)
and put it into Notepad++\plugins directory and then restart Notepad++.

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
[sql pretty printer desktop version](http://www.dpriver.com/)


####Contact
http://www.dpriver.com

support@dpriver.com

https://github.com/sqlparser/isf_notepad