ku = .2; %the system's gain
tau = 0.5; %the time constant of the system
Desired_temperature = 20; % the desired setpoint temperature.
Current_temperature = 10; %This temperature may comes from a sensor

Values_for_Ku = linspace(5 , 0.5 , 5);
values_for_tau = linspace(1.5 , 0.5 , 5);

model = gcs;

for i=1:numel(values_for_tau)

    ku = Values_for_Ku(i);
    tau = values_for_tau(i);

    results = sim(model);
    plot(results.logsout.get("Temp").Values);
    xlim([0,10]);
    ylim([0,25]);
    hold on
    LegendOfPlot{i} = "(Tau,ku)=( " + num2str(values_for_tau(i)) + " , "+num2str(Values_for_Ku(i))+" )";
    grid on
end

legend(LegendOfPlot);