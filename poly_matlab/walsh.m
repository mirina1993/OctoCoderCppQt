clear all;
x=1;
N=6;%log walsh matrix dimension
for i=1:1:N
    temp=x;
    x=[temp temp;temp -temp];
    i=i+1;
end