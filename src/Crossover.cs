using GeneticSharp.Domain.Chromosomes;
using System;
using System.Linq;
using UnityEngine;
using GeneticSharp.Domain.Randomizations;
using System.Collections.Generic;
using GeneticSharp.Domain.Crossovers;

namespace GeneticSharp.Runner.UnityApp.Commons
{
    public class Crossover : ICrossover
    {

        public int ParentsNumber { get; private set; }

        public int ChildrenNumber { get; private set; }

        public int MinChromosomeLength { get; private set; }

        public bool IsOrdered { get; private set; }

        protected float crossoverProbability;
        public Crossover(float crossoverProbability)
        {
            this.crossoverProbability = crossoverProbability;
            this.ParentsNumber = 2;
            this.ChildrenNumber = 2;
            this.MinChromosomeLength = 2;
            this.IsOrdered = true;
        }

        public IList<IChromosome> Cross(IList<IChromosome> parents)
        {
            if (RandomizationProvider.Current.GetDouble() > crossoverProbability)
            {
                return parents.Select(p => p.Clone()).ToList();
            }

            IChromosome parent1 = parents[0];
            IChromosome parent2 = parents[1];
            IChromosome offspring1 = parent1.Clone();
            IChromosome offspring2 = parent2.Clone();

            if (parent1.Length > 2)
            {   
                // Choose a random reference point
                int crossoverPoint = RandomizationProvider.Current.GetInt(1, parent1.Length - 1);

                // Swap the genes to the right of the reference point
                for (int i = crossoverPoint; i < parent1.Length; i++)
                {
                    Gene tempGene = offspring1.GetGene(i);
                    offspring1.ReplaceGene(i, offspring2.GetGene(i));
                    offspring2.ReplaceGene(i, tempGene);
                }
            }

            return new List<IChromosome> { offspring1, offspring2 };
        }
    }
}