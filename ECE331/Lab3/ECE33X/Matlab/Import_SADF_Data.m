function [D,S]=Import_SADF_Data()
% Presents a file-selection dialog and imports text (typically instrument 
% setup information) and numerical data (typically instrument measurements)
% from a Simple ASCII Data Formatted (SADF) Comma Delimited Value (.csv) 
% file, as saved by the LabView program HP54600B_ReadTraces.vi.
% [Data, Setup]=Import_SADF_Data
%
% Data is accessed as follows: Data(blocknumber,samplenumber,column)
%  where:
%   "blocknumber" is the acquisition number in the file, starting with 1.
%   (Blocknumber is used when multiple captures (acquisitions) were 
%    saved to the same file.)
%   "samplenumber" is the measurement sample number, starting with 
%    1 as the first data point taken. If the data is from an oscilloscope, 
%    this will correspond to leftmost point visible on the scope screen.
%   "column" is the column in file, starting with 1. Typically each column
%    represents a different measurement type, such as time of measurement, 
%    voltage at point A, current at point A, voltage at point B, etc. 
%    If the data is from an oscilloscope, this will typically correspond 
%    to the time axis (as channel 1) and the scope's input channels 1 and 2  
%    as columns 2 and 3 respectively.
%
% Setup is accessed as follows:
% Setup{blocknumber,itemnumber}{column}{1}
%  where:
%   "blocknumber" is as above.
%   "itemnumber" is a row index into the list of text items.
%    Typically the first item is a user comment and does not have a 2nd
%    column.
%   "column" is a column index into the list of text items.
%    Usually column 1 is an item name, and column 2 is a value.
%    If the data is from an oscilloscope, the following is typical:
%    column=1 will retrieve the parameter name (frequently a GPIB command)
%    column=2 will retrieve the value returned by the scope.

% Bring up a graphical file selection window
[FileName,PathName] = uigetfile('*.csv','Please select a .csv file with SADF formatted data','Data.csv');
% If user canceled, return with empty data sets
if isequal(FileName,0)
   disp('User selected Cancel')
   D=[];
   S={};
   return;
else % otherwise display the filename selected
   fname=fullfile(PathName, FileName);
   disp(['User selected ', fname])
end

% Open the file for reading in text mode
[fid,message] = fopen(fname, 'rt');
% If there was an error, display it and return with empty data sets
if fid == -1
    disp(message)
    D=[];
    S={};
    return;
else % Otherwise, read and parse the file
    % Initialize local variables
    block=0;    % Which acquisition data block we're in (used for 
                %  multiple scope captures in a single file)
    numlines=0; % File line counter. Not currently used.
    txtline=0;  % Keeps track of position in text comment/setup section
    intext=0;   % 1 if currently in a text comment/setup section. 
                %  Note these sections always precede the numerical data,
                %  so a switch from numerical data to textual data 
                %  indicates a new block's (acquisition's) data has begun.
    k=0;        % Keeps track of position in Numerical data section.
    while feof(fid) == 0    % while not at end of file,
        tline = fgetl(fid); % read the next line of ASCII text
         % Extract any comma-separated single-quoted text
        T={regexp(tline,'''[^'']*''','match')}; 
        if length(T{1})>0       % If quoted text was found,
            if intext==0        %  and we weren't already in a text block,
                block=block+1;  %  then the next block has begun. Count up one,
                txtline=0;      %  and re-zero in-block position counters.
                k=0;
                % Let the user know what's happening
                disp(sprintf('Reading Simple ASCII Data Format block %d', block));
            end
            intext=1; % We are in a text block, so set the flag to 1.
            % For each piece of quoted text found, strip off the quotes
            %  themselves and store the plain text in temporary cell T.
            for l=1:length(T{1})
                T{1}{l}=regexp(T{1}{l},'[^'']*','match');
            end
            txtline=txtline+1;  % Increment in-block text position counter
            S(block,txtline)=T; % Append temp cell T to Setup cell array
        else    % If quoted text was not found, we have left the 
                %  text/comment section and are probably in the numeric
                %  data section.
            intext=0;   % Clear the in-text-block flag to 0.
            tmp=sscanf(tline,'%g,');  % Attempt to read comma separated 
                                      %  numerical values.
            % If numerical values were successfully read, store them in
            %  the Data array.
            if length(tmp)>0
                k=k+1;                % Increment numerical position counter
                D(block,k,:)=tmp';    % Store numerical data
            end
        end
        numlines=numlines+1;    % Increment file line counter
    end     % endwhile. Go back and read the next line.
    fclose(fid);    % Close file when done.
    disp('done.');  % Let user know we're done reading the file.
end
end    % End of function definition.

