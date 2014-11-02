clear all;
close all;
%read signal from file
fid=fopen('beacon1ch .sig', 'r');
format short;
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

% split to Re and Im parts
    signal = fread(fid, 'int16');
    re = signal(1:2:end);
    im = signal(2:2:end);
    
% create complex signal and plot its beginning
signal_global=complex(re,im);
%signal_global=[signal_gl(1:700)' PRS' signal_gl(1212:5000)' ]';

% find packet start
for k=1:1:length(signal_global)-510
    corrvector(k)=corr(signal_global(k:(510+k)),PRS);
end
    %most_corr_coeffs=abs(sort(corrvector,2,'descend'));
    [start,position]=max(corrvector);
    
    %calculate phase angle
        
    phi_signal=phase(signal_global);
    abs_signal=abs(signal_global);
    phi_correct=phi_signal+phase(start);
    
    [x, y]=pol2cart(phi_correct,abs_signal);
    signal_with_phase_corr=complex(x,y);
    
    %new corr
for k_1=1:1:length(signal_with_phase_corr)-510
    corrvector_norm(k_1)=corr(signal_with_phase_corr(k_1:k_1+510),PRS);
end
    %most_corr_coeffs_1=abs(sort(corrvector_norm,'descend'));
    [start_1,position_1]=max(corrvector_norm);