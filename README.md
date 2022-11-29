# Overhead Tank Intelligent Water Level Controller
This project uses only 3 sensing elements. You have to dip 3 wires in water tank at unequal levels. The wire from pin A1 is kept at top level of the tank. Then the wire from pin A0 is kept at the bottom level of the tank. And the third wire is dipped throughout down to the bottom of the tank.<br>

## Brief Details
This code was developed by me for Vidyasagar Academy students, www.vsa.edu.in<br>
License: You can use it for any purpose as long as you don't claim that you are the author of this program and you don't alter License terms and formulations (as given in the code at lines 1-10 of this .ino file).<br>

## Important Note
Refer the circuit of this project, before using this code.<br>
The analog input pins (A0 & A1) must be returned to ground via 100k resistor each. Refer circuit diagram.<br>
Then apply the water level signal to these two pins: Full or Empty<br>

## Circuit Diagram
<img src="https://github.com/dsvidyasagar/Overhead-Tank-Intelligent-Water-Level-Controller/blob/main/Circuit.png" alt="Overhead Tank Intelligent Water Level Controller Circuit" width="50%" height="50%"><br>
 <figcaption>You can construct the circuit on breadboard</figcaption>
### Important Note
This part of the code is very important to note. It makes correct controlling of the pump without any false triggering.<br><br>
<pre>
 &nbsp;<font color="#5e6d03">if</font><font color="#000000">(</font><font color="#000000">f</font><font color="#434f54">==</font><font color="#00979c">HIGH</font> <font color="#434f54">&amp;&amp;</font> <font color="#000000">e</font><font color="#434f54">==</font><font color="#00979c">HIGH</font> <font color="#434f54">&amp;&amp;</font> <font color="#000000">p</font><font color="#434f54">==</font><font color="#00979c">HIGH</font><font color="#000000">)</font> <font color="#434f54">&#47;&#47; tank is full so pump is off</font>
 &nbsp;<font color="#000000">{</font>
 &nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">2000</font><font color="#000000">)</font><font color="#000000">;</font> <font color="#434f54">&#47;&#47; just a perceptible pause </font>
 &nbsp;&nbsp;&nbsp;<font color="#434f54">&#47;&#47; now we have to read status of &#34;e&#34; input again.</font>
 &nbsp;&nbsp;&nbsp;<font color="#434f54">&#47;&#47; because, when tank is filling up through a water tap, </font>
 &nbsp;&nbsp;&nbsp;<font color="#434f54">&#47;&#47; there might be splashes in water level, which may create false alarm.</font>
 &nbsp;&nbsp;&nbsp;<font color="#434f54">&#47;&#47; so to avoid false alarm, we read the status of input &#34;e&#34; for 10 seconds.</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">f</font><font color="#434f54">=</font><font color="#d35400">digitalRead</font><font color="#000000">(</font><font color="#000000">Full</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">1000</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">f</font><font color="#434f54">=</font><font color="#d35400">digitalRead</font><font color="#000000">(</font><font color="#000000">Full</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">1000</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">f</font><font color="#434f54">=</font><font color="#d35400">digitalRead</font><font color="#000000">(</font><font color="#000000">Full</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">1000</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">f</font><font color="#434f54">=</font><font color="#d35400">digitalRead</font><font color="#000000">(</font><font color="#000000">Full</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">1000</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">f</font><font color="#434f54">=</font><font color="#d35400">digitalRead</font><font color="#000000">(</font><font color="#000000">Full</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">1000</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">f</font><font color="#434f54">=</font><font color="#d35400">digitalRead</font><font color="#000000">(</font><font color="#000000">Full</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">1000</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">f</font><font color="#434f54">=</font><font color="#d35400">digitalRead</font><font color="#000000">(</font><font color="#000000">Full</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">1000</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">f</font><font color="#434f54">=</font><font color="#d35400">digitalRead</font><font color="#000000">(</font><font color="#000000">Full</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">1000</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">f</font><font color="#434f54">=</font><font color="#d35400">digitalRead</font><font color="#000000">(</font><font color="#000000">Full</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">1000</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">f</font><font color="#434f54">=</font><font color="#d35400">digitalRead</font><font color="#000000">(</font><font color="#000000">Full</font><font color="#000000">)</font><font color="#000000">;</font> 
 &nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">1000</font><font color="#000000">)</font><font color="#000000">;</font>

 &nbsp;&nbsp;&nbsp;<font color="#5e6d03">if</font><font color="#000000">(</font><font color="#000000">f</font><font color="#434f54">==</font><font color="#00979c">HIGH</font> <font color="#434f54">&amp;&amp;</font> <font color="#000000">e</font><font color="#434f54">==</font><font color="#00979c">HIGH</font> <font color="#434f54">&amp;&amp;</font> <font color="#000000">p</font><font color="#434f54">==</font><font color="#00979c">HIGH</font><font color="#000000">)</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">{</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#d35400">delay</font><font color="#000000">(</font><font color="#000000">100</font><font color="#000000">)</font><font color="#000000">;</font> <font color="#434f54">&#47;&#47; just a perseptible pause</font>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#d35400">digitalWrite</font><font color="#000000">(</font><font color="#000000">Pump</font><font color="#434f54">,</font><font color="#00979c">LOW</font><font color="#000000">)</font><font color="#000000">;</font>
 &nbsp;&nbsp;&nbsp;<font color="#000000">}</font> 

</pre>
