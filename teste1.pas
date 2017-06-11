program exemplo75 (input, output);
var a:integer;
var b:integer;
	function add1(var b:integer):integer;
	begin
		add1:=b+1
	end;
begin
	a:=0;
	write(add1(a))
end.
