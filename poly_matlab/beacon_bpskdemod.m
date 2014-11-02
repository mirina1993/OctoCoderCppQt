clear all;
fid=fopen('beacon1.sig', 'r');
x=fread(fid);
format short;
%format hex;
%x=[1 2 3 4 5 6 7 8 9 10];
k=size(x);
j=1;i=1;
for k_index=1:1:k(1)
    if (rem(k_index,2)==1)
        re(j)=x(k_index);j=j+1;
    else im(i)=x(k_index);i=i+1; 
    end;  
k_index=k_index+1;
end;
signal=complex(re,im);
amp=abs(signal);
plot(amp(1:200));
signal_demod=pskdemod(signal,4);
scatterplot(signal_demod);
