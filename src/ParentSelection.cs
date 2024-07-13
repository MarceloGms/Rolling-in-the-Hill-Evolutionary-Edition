using System.Collections.Generic;
using System.Linq;
using GeneticSharp.Domain.Chromosomes;
using GeneticSharp.Domain.Populations;
using GeneticSharp.Domain.Randomizations;
using GeneticSharp.Domain.Selections;
using GeneticSharp.Runner.UnityApp.Car;
using UnityEngine;

public class ParentSelection : SelectionBase
{
    private int tournamentSize;

    public ParentSelection(int tournamentSize) : base(2)
    {
        this.tournamentSize = tournamentSize;
    }

    protected override IList<IChromosome> PerformSelectChromosomes(int number, Generation generation)
    {
        IList<CarChromosome> population = generation.Chromosomes.Cast<CarChromosome>().ToList();
        IList<IChromosome> selectedParents = new List<IChromosome>();

        for (int i = 0; i < number; i++)
        {
            IList<CarChromosome> tournamentParticipants = new List<CarChromosome>();

            // Get 5 random subjects
            for (int j = 0; j < tournamentSize; j++)
            {
                int randomIndex = RandomizationProvider.Current.GetInt(0, population.Count);
                tournamentParticipants.Add(population[randomIndex]);
            }

            // Choose the best one
            CarChromosome bestParticipant = tournamentParticipants
                .OrderByDescending(chromosome => chromosome.Fitness)
                .First();

            selectedParents.Add(bestParticipant);
        }

        return selectedParents;
    }
}