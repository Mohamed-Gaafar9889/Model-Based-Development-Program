g = 9.8;

Initial_displacement = 0;
Initial_Velocity = 0.1;

Length = linspace(1,2.5,3);

for i=1 : numel(Length)

end

for i=1 : numel(Length)
    Lengths_legends{i} = "At L = " + num2str(Length(i));
    L = Length(i);

    model = sim(gcs);

    figure(1)
    plot(model.logsout.get("theta_Dash").Values);
    ylabel('Angular_Velocity');
    xlabel('Time');
    grid on
    hold on

    figure(2)
    plot(model.logsout.get("theta").Values);
    ylabel('displacement');
    xlabel('Time');
    grid on

    hold on
end

figure(1)
legend(Lengths_legends);

figure(2)
legend(Lengths_legends);