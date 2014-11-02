clear all;
%sig=[1 1 1 0 0];
%tr=poly2trellis(3,[7 5]);
%code=convenc(sig,tr);
%err=randerr(1,10,1);
%code_err=mod(code+err,2);
%decode=vitdec(code_err,tr,5,'trunc','hard');
%num=sum(mod(decode-sig,2));
%ber=biterr(decode,sig,'row-wise');
N_max=5000;
num_of_errors=1;
for i=1:1:N_max
sig1=randint(1,100);
tr1=poly2trellis(9,[753 561]);
code1=convenc(sig1,tr1);
err_length=size(code1);
err=randerr(1,err_length(2),num_of_errors);
code1_err=mod(code1+err,2);
decode1=vitdec(code1_err,tr1,5,'trunc','hard');
ber(i)=biterr(decode1,sig1,'row-wise');
end;
t_stat_0_95=1.96*std(ber)/sqrt(N_max);
ber_average_percentage=(sum(ber)/N_max)*100;
ber_average_percentage_max=ber_average_percentage+t_stat_0_95;
ber_average_percentage_min=ber_average_percentage-t_stat_0_95;

