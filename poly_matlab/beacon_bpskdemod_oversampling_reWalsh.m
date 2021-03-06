clear all;
close all;
%read signal from file
fid=fopen('beacon1ch .sig', 'r');
format short;

% split to Re and Im parts
    signal = fread(fid, 'int16');
    re = signal(1:2:end);
    im = signal(2:2:end);
    
% create complex signal and plot its beginning
signal_global=complex(re,im);
signal=signal_global(1:2:length(signal_global));




% signal bpsk demodulation
signal_demod=pskdemod(signal,2);
scatterplot(signal_demod);

%
 PRS=[1;  1;  1;  1;  1;  1; -1; -1; -1; -1;  1;  1;  1;  1; -1;  1;  1;  1; -1; -1; -1; -1;  1; -1;  1;  1; -1; -1;  1;  1; -1;  1;
          1; -1;  1;  1;  1;  1; -1;  1; -1; -1; -1; -1;  1;  1;  1; -1; -1;  1;  1; -1; -1; -1; -1;  1; -1; -1;  1; -1; -1; -1;  1; -1;
          1; -1;  1;  1;  1; -1;  1; -1;  1;  1;  1;  1; -1; -1;  1; -1; -1;  1; -1;  1;  1;  1; -1; -1;  1;  1;  1; -1; -1; -1; -1; -1;
         -1;  1;  1;  1; -1;  1;  1;  1; -1;  1; -1; -1;  1;  1;  1;  1; -1;  1; -1;  1; -1; -1;  1; -1;  1; -1; -1; -1; -1; -1; -1;  1;
         -1;  1; -1;  1; -1;  1; -1;  1;  1;  1;  1;  1; -1;  1; -1;  1;  1; -1;  1; -1; -1; -1; -1; -1;  1;  1; -1;  1;  1;  1; -1;  1;
          1; -1;  1;  1; -1;  1; -1;  1;  1; -1; -1; -1; -1; -1;  1; -1;  1;  1;  1; -1;  1;  1;  1;  1;  1; -1; -1; -1;  1;  1;  1;  1;
         -1; -1;  1;  1; -1;  1; -1; -1;  1;  1; -1;  1; -1;  1;  1;  1; -1; -1; -1;  1;  1; -1;  1; -1; -1; -1;  1; -1;  1;  1;  1;  1;
          1;  1;  1; -1;  1; -1; -1;  1; -1;  1;  1; -1; -1; -1;  1; -1;  1; -1; -1;  1;  1; -1; -1; -1;  1;  1; -1; -1; -1; -1; -1; -1;
         -1;  1;  1; -1; -1;  1;  1; -1; -1;  1; -1;  1; -1;  1;  1; -1; -1;  1; -1; -1;  1;  1;  1;  1;  1;  1; -1;  1;  1; -1;  1; -1;
         -1;  1; -1; -1;  1; -1; -1;  1;  1; -1;  1;  1;  1;  1;  1;  1; -1; -1;  1; -1;  1;  1; -1;  1; -1;  1; -1; -1; -1; -1;  1; -1;
          1; -1; -1; -1;  1; -1; -1;  1;  1;  1; -1;  1;  1; -1; -1;  1; -1;  1;  1;  1;  1; -1;  1;  1; -1; -1; -1; -1;  1;  1; -1;  1;
         -1;  1; -1;  1; -1; -1;  1;  1;  1; -1; -1;  1; -1; -1; -1; -1;  1;  1; -1; -1; -1;  1; -1; -1; -1; -1;  1; -1; -1; -1; -1; -1;
         -1; -1; -1;  1; -1; -1; -1;  1; -1; -1; -1;  1;  1; -1; -1;  1; -1; -1; -1;  1;  1;  1; -1;  1; -1;  1; -1;  1;  1; -1;  1;  1;
         -1; -1; -1;  1;  1;  1; -1; -1; -1;  1; -1; -1;  1; -1;  1; -1;  1; -1; -1; -1;  1;  1; -1;  1;  1; -1; -1;  1;  1;  1;  1;  1;
         -1; -1;  1;  1;  1;  1; -1; -1; -1;  1; -1;  1;  1; -1;  1;  1;  1; -1; -1;  1; -1;  1; -1; -1;  1; -1; -1; -1; -1; -1;  1; -1;
         -1;  1;  1; -1; -1;  1;  1;  1; -1;  1; -1; -1; -1;  1;  1;  1;  1;  1; -1;  1;  1;  1;  1; -1; -1; -1; -1; -1;  1;  1;  1  ];

% create Walsh matrix 64x64
x=1;
N=6;%log walsh matrix dimension
for i=1:1:N
    temp=x;
    x=[temp temp;temp -temp];
    i=i+1;
end

%convert signal to bipolar form
for l=1:1:length(signal_demod)
    if (signal_demod(l)==0)
       deWalsh(l)=-1;
    else deWalsh(l)=1;
    end;
end;
% find packet start
for k=1:1:length(signal)-510
    corr_PRS(k)=corr(signal(k:k+510),PRS);
end
    most_corr_coeffs=abs(sort(corr_PRS,2,'descend'));
    [start,position]=max(corr_PRS);
    %remove PRS from packet
    packet_noised_with_PRS=deWalsh(position+510:length(deWalsh));
    %zero pad the packet's tail
    packet_noised_with_PRS_matrix=vec2mat(packet_noised_with_PRS,511);
    
 
for p=1:1:4
    packet_clean(p,:)=packet_noised_with_PRS_matrix(p,:).*PRS'
end;
 
%convert to 64 columns matrix
packet_clean_matrix=vec2mat(packet_clean,64);
packet_to_decode_matrix=packet_clean_matrix(1:24,:)

 
 packet_deWalsh_matrix=corr(packet_to_decode_matrix',x');
 for i=1:1:24
 [max_corr(i), num_of_sequence(i)]=max(packet_deWalsh_matrix(i,:));
  end;
 
 sig1=de2bi(num_of_sequence-1);
 sig1=sig1(:);
num_of_errors=0;

deinterleaver = [0; 133; 122; 111; 100; 89; 78; 67; 56; 45; 34; 23; 12; 1; 134; 123; 
	112; 101; 90; 79; 68; 57; 46; 35; 24; 13; 2; 135; 124; 113; 102; 91; 
	80; 69; 58; 47; 36; 25; 14; 3; 136; 125; 114; 103; 92; 81; 70; 59; 
	48; 37; 26; 15; 4; 137; 126; 115; 104; 93; 82; 71; 60; 49; 38; 27; 
	16; 5; 138; 127; 116; 105; 94; 83; 72; 61; 50; 39; 28; 17; 6; 139; 
	128; 117; 106; 95; 84; 73; 62; 51; 40; 29; 18; 7; 140; 129; 118; 107; 
	96; 85; 74; 63; 52; 41; 30; 19; 8; 141; 130; 119; 108; 97; 86; 75; 
	64; 53; 42; 31; 20; 9; 142; 131; 120; 109; 98; 87; 76; 65; 54; 43; 
	32; 21; 10; 143; 132; 121; 110; 99; 88; 77; 66; 55; 44; 33; 22; 11];

sig1 = sortrows ([deinterleaver sig1],1);

tr1=poly2trellis(9,[753 561]);
%code1=convenc(sig1,tr1);
decode1=vitdec(sig1(:,2)',tr1,20,'term','hard');
packet=mat2str(decode1)






 
 
 







