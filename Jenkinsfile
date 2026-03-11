pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                // Move into the source directory where the Makefile is
                dir('source') {
                    sh 'make clean && make > ../buildlog.txt 2>&1'
                }
            }
        }

        stage('Coding Standards') {
            steps {
                // Run cppcheck on the source directory
                sh 'cppcheck source/ --enable=all --suppress=missingIncludeSystem --addon=misra.py > coding_standards_report.txt 2>&1 || true'
            }
        }

        stage('Static Analysis') {
            steps {
                sh 'cppcheck source/ > static-analysis-report.txt 2>&1 || true'
            }
        }
    }
    
    post {
        always {
            // Archive logs and the compiled .o files (found in source/src/ or source/)
            archiveArtifacts artifacts: '*.txt, source/**/*.o', fingerprint: true
        }
    }
}